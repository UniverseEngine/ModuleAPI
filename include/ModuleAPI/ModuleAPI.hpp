#pragma once

#include <unordered_map>
#include <string>

namespace Universe::ModuleAPI
{
    using Configuration = std::unordered_map<std::string, std::string>;
    using Rules         = std::unordered_map<std::string, std::string>;

    class IServerInterface {
    public:
        virtual std::string GetServerName()                      = 0;
        virtual uint32_t    GetServerPort()                      = 0;
        virtual uint8_t     GetCurrentPlayerCount()              = 0;
        virtual uint8_t     GetMaximumPlayers()                  = 0;
        virtual uint8_t     GetGameType()                        = 0;
        virtual bool        HasPassword()                        = 0;
        virtual std::string GetGameMode()                        = 0;
        virtual std::string GetServerVersion()                   = 0;
        virtual Rules       GetServerRules()                     = 0;
        virtual std::string GetClientNameByIndex(uint32_t index) = 0;
    };

    class IModuleInterface {
    public:
        virtual const Configuration& GetConfiguration() const = 0;
        virtual IServerInterface*    GetServer()              = 0;
    };

    struct ModuleDetails
    {
        std::string moduleName;
        std::string moduleDescription;
        std::string moduleAuthor;
    };

    class IModuleHandler {
    public:
        virtual void OnModuleLoad(ModuleDetails& details, IModuleInterface* moduleInterface) = 0;
        virtual void OnModuleTick()                                                          = 0;
    };
} // namespace Universe::ModuleAPI
