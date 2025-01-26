#pragma once

#include <ServerAPI.hpp>

#include <unordered_map>
#include <string>
#include <memory>

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __attribute__((visibility("default")))
#endif

namespace Universe
{
    using Configuration = std::unordered_map<std::string, std::string>;

    /**
     * @brief Interface for module-related operations.
     */
    class IServerModuleInterface {
    public:
        /**
         * @brief Get the configuration of the module.
         * @return A reference to the configuration map.
         */
        virtual const Configuration& GetConfiguration() const = 0;

        /**
         * @brief Get the server interface.
         * @return A pointer to the server interface.
         */
        virtual IServerInterface* GetServer() = 0;

        virtual ~IServerModuleInterface() = default;
    };

    /**
     * @brief Structure to hold module details.
     */
    struct ServerModuleDetails
    {
        std::string moduleName; ///< The name of the module.
        std::string moduleDescription; ///< The description of the module.
        std::string moduleAuthor; ///< The author of the module.
        std::string moduleVersion; ///< The version of the module.
    };

    /**
     * @brief Interface for handling module events.
     */
    class IServerModuleHandler {
    public:
        /**
         * @brief Called when a module is loaded.
         * @param details The details of the module.
         * @param moduleInterface The interface to the module.
         */
        virtual void OnModuleLoad(ServerModuleDetails& details, IServerModuleInterface* moduleInterface) = 0;

        /**
         * @brief Called on each tick of the module.
         */
        virtual void OnModuleTick() = 0;

        virtual ~IServerModuleHandler() = default;
    };
} // namespace Universe
