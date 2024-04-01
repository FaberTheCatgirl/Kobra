#include "stdafx.h"

// The class we are implementing
#include "IWMap.h"

// We need the following WraithX classes
#include "MemoryReader.h"
#include "BinaryReader.h"
#include "Strings.h"
#include "SettingsManager.h"
#include "FileSystems.h"

// We need the file classes
#include "CoDAssets.h"

IWMap::Entity::Entity(const std::string& className)
{
    KeyValuePairs["classname"] = className;
}

Vector3 ParseVector3FromString(const std::string& str)
{
    std::istringstream iss(str);

    float x, y, z;

    if (!(iss >> x >> y >> z))
        throw std::invalid_argument("Invalid string format for Vector3!");

    return Vector3(x, y, z);
}

IWMap::Entity IWMap::Entity::CreateMiscModel(const std::string& modelName, const std::string& originStr, const std::string& anglesStr, float modelScale)
{
    Entity result("misc_model");
    result.KeyValuePairs["model"] = modelName;

    // Parse the origin string into Vector3
    Vector3 origin = ParseVector3FromString(originStr);
    result.KeyValuePairs["origin"] = std::to_string(origin.X) + " " + std::to_string(origin.Y) + " " + std::to_string(origin.Z);

    // Parse the angles string into Vector3
    Vector3 angles = ParseVector3FromString(anglesStr);
    result.KeyValuePairs["angles"] = std::to_string(angles.X) + " " + std::to_string(angles.Y) + " " + std::to_string(angles.Z);
    result.KeyValuePairs["modelscale"] = std::to_string(modelScale);

    return result;
}

IWMap::IWMap()
{
    Entity worldspawn("worldspawn");

    worldspawn.KeyValuePairs["fsi"] = "default";
    worldspawn.KeyValuePairs["gravity"] = "800";
    worldspawn.KeyValuePairs["lodbias"] = "default";
    worldspawn.KeyValuePairs["lutmaterial"] = "luts_t7_default";
    worldspawn.KeyValuePairs["numOmniShadowSlices"] = "24";
    worldspawn.KeyValuePairs["numSpotShadowSlices"] = "64";
    worldspawn.KeyValuePairs["sky_intensity_factor0"] = "1";
    worldspawn.KeyValuePairs["sky_intensity_factor1"] = "1";
    worldspawn.KeyValuePairs["state_alias_1"] = "State 1";
    worldspawn.KeyValuePairs["state_alias_2"] = "State 2";
    worldspawn.KeyValuePairs["state_alias_3"] = "State 3";
    worldspawn.KeyValuePairs["state_alias_4"] = "State 4";

    Entities.push_back(worldspawn);
}

void IWMap::DumpToMap(const std::string& fileName)
{
    std::ofstream writer(fileName);

    writer << "iwmap 4\n";
    writer << "\"script_startingnumber\" 0\n";
    writer << "\"000_Global\" flags active\n";
    writer << "\"The Map\" flags expanded\n";

    for (size_t i = 0; i < Entities.size(); ++i)
    {
        writer << "// entity " << i << "\n";
        writer << "{\n";

        for (const auto& kvp : Entities[i].KeyValuePairs)
            writer << "\"" << kvp.first << "\" \"" << kvp.second << "\"\n";

        writer << "}\n";
    }
}