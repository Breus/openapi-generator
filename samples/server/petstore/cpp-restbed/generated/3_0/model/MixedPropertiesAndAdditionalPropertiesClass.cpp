/**
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.3.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "MixedPropertiesAndAdditionalPropertiesClass.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "helpers.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace org {
namespace openapitools {
namespace server {
namespace model {

MixedPropertiesAndAdditionalPropertiesClass::MixedPropertiesAndAdditionalPropertiesClass(boost::property_tree::ptree const& pt)
{
        fromPropertyTree(pt);
}


std::string MixedPropertiesAndAdditionalPropertiesClass::toJsonString(bool prettyJson /* = false */) const
{
	std::stringstream ss;
	write_json(ss, this->toPropertyTree(), prettyJson);
    // workaround inspired by: https://stackoverflow.com/a/56395440
    std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
    std::string result = std::regex_replace(ss.str(), reg, "$1");
    return result;
}

void MixedPropertiesAndAdditionalPropertiesClass::fromJsonString(std::string const& jsonString)
{
	std::stringstream ss(jsonString);
	ptree pt;
	read_json(ss,pt);
	this->fromPropertyTree(pt);
}

ptree MixedPropertiesAndAdditionalPropertiesClass::toPropertyTree() const
{
	ptree pt;
	ptree tmp_node;
	pt.put("uuid", m_Uuid);
	pt.put("dateTime", m_DateTime);
	// generate tree for map
    if (!m_map.empty()) {
        tmp_node = toPt(m_map);
        pt.add_child("map", tmp_node);
    }
    tmp_node.clear();
	return pt;
}

void MixedPropertiesAndAdditionalPropertiesClass::fromPropertyTree(ptree const &pt)
{
	ptree tmp_node;
	m_Uuid = pt.get("uuid", "");
	m_DateTime = pt.get("dateTime", "");
    if (pt.get_child_optional("map")) {
        m_map = fromPt<std::map<std::string, Animal>>(pt.get_child("map"));
    }
}

std::string MixedPropertiesAndAdditionalPropertiesClass::getUuid() const
{
    return m_Uuid;
}

void MixedPropertiesAndAdditionalPropertiesClass::setUuid(std::string value)
{
    m_Uuid = value;
}


std::string MixedPropertiesAndAdditionalPropertiesClass::getDateTime() const
{
    return m_DateTime;
}

void MixedPropertiesAndAdditionalPropertiesClass::setDateTime(std::string value)
{
    m_DateTime = value;
}


std::map<std::string, Animal> MixedPropertiesAndAdditionalPropertiesClass::getMap() const
{
    return m_map;
}

void MixedPropertiesAndAdditionalPropertiesClass::setMap(std::map<std::string, Animal> value)
{
    m_map = value;
}



std::vector<MixedPropertiesAndAdditionalPropertiesClass> createMixedPropertiesAndAdditionalPropertiesClassVectorFromJsonString(const std::string& json)
{
    std::stringstream sstream(json);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream,pt);

    auto vec = std::vector<MixedPropertiesAndAdditionalPropertiesClass>();
    for (const auto& child: pt) {
        vec.emplace_back(MixedPropertiesAndAdditionalPropertiesClass(child.second));
    }

    return vec;
}

}
}
}
}

