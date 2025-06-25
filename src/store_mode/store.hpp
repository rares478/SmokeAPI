#pragma once

#include <core/types.hpp>

namespace store {
    // Offset values are interpreted according to pointer arithmetic rules, i.e.
    // 1 unit offset represents 4 and 8 bytes in 32-bit and 64-bit architectures respectively.
    class StoreConfig {
    public:
        uint32_t client_engine_steam_client_internal_ordinal = 11;
        uint32_t steam_client_internal_interface_selector_ordinal = 18;
        std::string family_group_running_app_pattern = "55 8B ?? ?? EC C8 ?? ?? ?? 33";

        // We do not use *_WITH_DEFAULT macro to ensure that overriding
        // the store_mode config requires definition of all keys
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(
            StoreConfig, // NOLINT(misc-const-correctness)
            client_engine_steam_client_internal_ordinal,
            steam_client_internal_interface_selector_ordinal,
            family_group_running_app_pattern
        )

        bool operator==(const StoreConfig& other) const = default;
    };

    extern StoreConfig config;

    void init_store_mode();

}
