#pragma once

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
    using RulesMap = std::unordered_map<std::string, std::string>;

    /**
     * @brief Interface for server-related operations.
     */
    class IServerInterface {
    public:
        /**
         * @brief Get the server name.
         * @return The name of the server.
         */
        virtual const std::string& GetServerName() = 0;

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
        virtual const std::string& GetGameMode() = 0;

        /**
         * @brief Get the server version.
         * @return The version of the server.
         */
        virtual const std::string& GetServerVersion() = 0;

        /**

         * @brief Get the server rules.
         * @return A map of server rules.
         */
        virtual const RulesMap& GetServerRules() = 0;

        /**
         * @brief Get the client name by index.
         * @param index The index of the client.
         * @return The name of the client at the specified index.
         */
        virtual const std::string& GetClientNameByIndex(uint32_t index) = 0;

        virtual ~IServerInterface() = default;
    };
} // namespace Universe
