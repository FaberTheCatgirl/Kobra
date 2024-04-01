#pragma once

class IWMap
{
public:
    class Entity
    {
    public:
        std::map<std::string, std::string> KeyValuePairs;

        Entity(const std::string& className);

        IWMap::Entity CreateMiscModel(const std::string& modelName, const std::string& originStr, const std::string& anglesStr, float modelScale);
    };

    std::vector<Entity> Entities;

    IWMap();

    void DumpToMap(const std::string& fileName);
};