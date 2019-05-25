// Copyright [year] <Copyright Owner>
#ifndef MODULES_PIPELINES_INCLUDE_YAML_PARSER_H_
#define MODULES_PIPELINES_INCLUDE_YAML_PARSER_H_
#include "../../pch/include/precomp.h"

class YAMLParser {
 public:
    class Value;
    using Sequence = std::vector <Value>;
    class Mapping {
     private:
        std::map <std::string, Value> map;
     public:
        bool has_key(const std::string name) const;
        Value get_value(const std::string name) const;
        std::string get_string(const std::string name) const;
        Mapping get_mapping(const std::string name) const;
        Sequence get_sequence(const std::string name) const;
        const std::map <std::string, Value> get_map() const;
        friend class YAMLParser;
    };
    class Value {
     public:
        enum class Type {
            String, Mapping, Sequence
        };
     private:
        Type type;
        std::string string;
        Mapping mapping;
        Sequence sequence;
     public:
        Value() = default;
        void print(std::ostream &os, int indent);
        Value(const std::string &str, ...) : type(Type::String), string(str) {}
        Value(const Mapping &map, ...) : type(Type::Mapping), mapping(map) {}
        Value(const Sequence &seq, ...) : type(Type::Sequence), sequence(seq) {}
        const std::string &get_string() const;
        const Mapping &get_mapping() const;
        const Sequence &get_sequence() const;
        const Type get_type() const;
    };

 private:
    std::string file_name;
    std::unique_ptr<FILE, decltype(&fclose)> file;
    yaml_parser_t parser;
    struct YAMLEvent {
        yaml_event_type_t type;
        std::string value;
        YAMLEvent(const yaml_event_t &event, ...) :
            type(event.type),
            value(event.type == YAML_SCALAR_EVENT ?
            (const char *)event.data.scalar.value : "") {}
    };
    YAMLEvent get_next_event() {
        yaml_event_t event;
        if (!yaml_parser_parse(&parser, &event))
            throw std::runtime_error("Error parsing YAML at " +
                                    std::to_string(parser.problem_mark.line) +
                                    std::to_string(parser.problem_mark.column) +
                                    parser.problem);
        return YAMLEvent(event);
    }
    Mapping read_mapping();
    Sequence read_sequence();

 public:
    YAMLParser(std::string file_name, ...);
    YAMLParser(const YAMLParser &p, ...);
    YAMLParser::Value parse();
    ~YAMLParser();
    friend std::ostream &operator<<(std::ostream &os, YAMLParser::Value &val);
};

#endif  // MODULES_PIPELINES_INCLUDE_YAML_PARSER_H_
