// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

YAMLParser::YAMLParser(std::string file_name, ...) :
    file_name(file_name),
    file(fopen(file_name.c_str(), "r"), &fclose) {
    if (!file)
        throw std::runtime_error("YAMLParser: File is not found");
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, file.get());
}

YAMLParser::YAMLParser(const YAMLParser &p, ...) :
    file_name(p.file_name),
    file(fopen(file_name.c_str(), "r"), &fclose) {
    if (!file)
        throw std::runtime_error("YAMLParser: File is not found");
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, file.get());
}

YAMLParser::~YAMLParser() {
    yaml_parser_delete(&parser);
}

bool YAMLParser::Mapping::has_key(const std::string name) const {
    return map.find(name.data()) != map.end();
}

const std::string &YAMLParser::Value::get_string() const {
    if (type != Type::String)
        throw std::runtime_error("Value is not String type");
    return string;
}

const YAMLParser::Mapping &YAMLParser::Value::get_mapping() const {
    if (type != Type::Mapping)
        throw std::runtime_error("Value is not Mapping type");
    return mapping;
}

const YAMLParser::Sequence &YAMLParser::Value::get_sequence() const {
    if (type != Type::Sequence)
        throw std::runtime_error("Value is not Sequence type");
    return sequence;
}

const YAMLParser::Value::Type YAMLParser::Value::get_type() const {
    return type;
}

YAMLParser::Value YAMLParser::Mapping::get_value(const std::string name) const {
    auto res = map.find(name.data());
    if (res == map.end())
        throw std::runtime_error("Wrong key");
    return (*res).second;
}

std::string YAMLParser::Mapping::get_string
                (const std::string name) const {
    auto res = map.find(name.data());
    if (res == map.end())
        throw std::runtime_error("Wrong key");
    return (*res).second.get_string();
}

YAMLParser::Mapping YAMLParser::Mapping::get_mapping
                (const std::string name) const {
    auto res = map.find(name.data());
    if (res == map.end())
        throw std::runtime_error("Wrong key");
    return (*res).second.get_mapping();
}

YAMLParser::Sequence YAMLParser::Mapping::get_sequence
                (const std::string name) const {
    auto res = map.find(name.data());
    if (res == map.end())
        throw std::runtime_error("Wrong key");
    return (*res).second.get_sequence();
}

const std::map <std::string, YAMLParser::Value>
                YAMLParser::Mapping::get_map() const {
    return map;
}

YAMLParser::Value YAMLParser::parse() {
    int preparing = 2;
    while (preparing) {
        YAMLEvent event = get_next_event();
        switch (event.type) {
        case YAML_STREAM_START_EVENT:
            if (preparing != 2)
                throw std::runtime_error("Unexpected"
                                        "YAML_STREAM_START_EVENT");
            preparing = 1;
            break;
        case YAML_DOCUMENT_START_EVENT:
            if (preparing != 1)
                throw std::runtime_error("Unexpected"
                                        "YAML_DOCUMENT_START_EVENT");
            preparing = 0;
            break;
        default:
            throw std::runtime_error("Unexpected event " +
                                    std::to_string(event.type));
        }
    }
    YAMLEvent event = get_next_event();
    switch (event.type) {
    case YAML_SCALAR_EVENT:
        return Value(event.value);
        break;
    case YAML_SEQUENCE_START_EVENT:
        return Value(read_sequence());
        break;
    case YAML_MAPPING_START_EVENT:
        return Value(read_mapping());
        break;
    default:
        throw std::runtime_error("Unexpected event " +
                                    std::to_string(event.type));
    }
}

YAMLParser::Mapping YAMLParser::read_mapping() {
    Mapping mapping;
    while (true) {
        std::string key;
        YAMLEvent event = get_next_event();
        // Reading key
        switch (event.type) {
        case YAML_SCALAR_EVENT:
            key = event.value;
            break;
        case YAML_MAPPING_END_EVENT:
            return mapping;
            break;
        default:
            throw std::runtime_error("Unexpected event " +
                                    std::to_string(event.type));
        }
        event = get_next_event();
        switch (event.type) {
        case YAML_SCALAR_EVENT:
            mapping.map.emplace(key, event.value);
            break;
        case YAML_SEQUENCE_START_EVENT:
            mapping.map.emplace(key, read_sequence());
            break;
        case YAML_MAPPING_START_EVENT:
            mapping.map.emplace(key, read_mapping());
            break;
        default:
            throw std::runtime_error("Unexpected event " +
                                    std::to_string(event.type));
        }
    }
}

YAMLParser::Sequence YAMLParser::read_sequence() {
    Sequence seq;
    while (true) {
        YAMLEvent event = get_next_event();
        switch (event.type) {
        case YAML_SCALAR_EVENT:
            seq.emplace_back(event.value);
            break;
        case YAML_SEQUENCE_START_EVENT:
            seq.emplace_back(Value(read_sequence()));
            break;
        case YAML_MAPPING_START_EVENT:
            seq.emplace_back(Value(read_mapping()));
            break;
        case YAML_SEQUENCE_END_EVENT:
            return seq;
        default:
            throw std::runtime_error("Unexpected event " +
                                    std::to_string(event.type));
        }
    }
}

std::ostream &operator<<(std::ostream &os, YAMLParser::Value &val) {
    val.print(os, 0);
    return os;
}

void YAMLParser::Value::print(std::ostream &os, int indent) {
    switch (type) {
    case Type::String:
        for (int i = 0; i < indent; ++i)
            os << " ";
        os << "Type::String" << std::endl;
        for (int i = 0; i < indent; ++i)
            os << " ";
        os << string << std::endl;
        break;
    case Type::Mapping:
        for (int i = 0; i < indent; ++i)
            os << " ";
        os << "Type::Mapping" << std::endl;
        for (auto &el : mapping.map) {
            for (int i = 0; i < indent; ++i)
                os << " ";
            os << el.first << std::endl;
            el.second.print(os, indent + 1);
        }
        break;
    case Type::Sequence:
        for (int i = 0; i < indent; ++i)
            os << " ";
        os << "Type::Sequence" << std::endl;
        for (auto &el : sequence)
            el.print(os, indent + 1);
        break;
    }
}
