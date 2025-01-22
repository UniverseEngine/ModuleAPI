#pragma once

#include <unordered_map>
#include <string>
#include <memory>

// Entry point must declare the ModuleAPIExport macro to export the function.
#ifdef _WIN32
#define ModuleAPIExport extern "C" __declspec(dllexport)
#else
#define ModuleAPIExport extern "C" __attribute__((visibility("default")))
#endif

namespace Universe::ModuleAPI
{
    using Configuration = std::unordered_map<std::string, std::string>;
    using Rules         = std::unordered_map<std::string, std::string>;

    /**
     * @brief Interface for server-related operations.
     */
    class IServerInterface {
    public:
        /**
         * @brief Get the server name.
         * @return The name of the server.
         */
        virtual std::string GetServerName() = 0;

        /**
         * @brief Get the server port.
         * @return The port number of the server.
         */
        virtual uint32_t GetServerPort() = 0;

        /**
         * @brief Get the current player count.
         * @return The number of players currently connected to the server.
         */
        virtual uint8_t GetCurrentPlayerCount() = 0;

        /**
         * @brief Get the maximum number of players allowed on the server.
         * @return The maximum number of players.
         */
        virtual uint8_t GetMaximumPlayers() = 0;

        /**
         * @brief Get the game type.
         * @return The type of the game.
         */
        virtual uint8_t GetGameType() = 0;

        /**
         * @brief Check if the server has a password.
         * @return True if the server has a password, false otherwise.
         */
        virtual bool HasPassword() = 0;

        /**
         * @brief Get the game mode.
         * @return The game mode.
         */
        virtual std::string GetGameMode() = 0;

        /**
         * @brief Get the server version.
         * @return The version of the server.
         */
        virtual std::string GetServerVersion() = 0;

        /**

         * @brief Get the server rules.
         * @return A map of server rules.
         */
        virtual Rules GetServerRules() = 0;

        /**
         * @brief Get the client name by index.
         * @param index The index of the client.
         * @return The name of the client at the specified index.
         */
        virtual std::string GetClientNameByIndex(uint32_t index) = 0;

        virtual ~IServerInterface() = default;
    };

    /**
     * @brief Interface for module-related operations.
     */
    class IModuleInterface {
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

        virtual ~IModuleInterface() = default;
    };

    /**
     * @brief Structure to hold module details.
     */
    struct ModuleDetails
    {
        std::string moduleName;        ///< The name of the module.
        std::string moduleDescription; ///< The description of the module.
        std::string moduleAuthor;      ///< The author of the module.
        std::string moduleVersion;     ///< The version of the module.
    };

    /**
     * @brief Interface for handling module events.
     * @details This interface is used to handle events related to module loading and ticking.
     * @note Users must implement this interface to create a functional module that can handle these events.
     *       Additionally, an entry point function must be provided to load the module.
     *
     * Example of an entry point function for a module named "HashingModule":
     * extern "C" ModuleAPIExport IModuleHandler* CreateModuleHandler()
     * {
     *     return HashingModule::m_moduleHandler.get();
     * }
     */
    class IModuleHandler {
    public:
        /**
         * @brief Called when a module is loaded.
         * @param details The details of the module.
         * @param moduleInterface The interface to the module.
         */
        virtual void OnModuleLoad(ModuleDetails& details, IModuleInterface& moduleInterface) = 0;

        /**
         * @brief Called on each tick of the module.
         */
        virtual void OnModuleTick() = 0;

        virtual ~IModuleHandler() = default;
    };
} // namespace Universe::ModuleAPI

