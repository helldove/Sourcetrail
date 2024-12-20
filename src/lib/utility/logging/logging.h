#pragma once
#include <fmt/xchar.h>

#include <spdlog/spdlog.h>

#include "utilityString.h"

// Macro to strip the prefix from __FILE__
#define RELATIVE_FILE_PATH (__FILE__ + SOURCE_PATH_PREFIX_LEN)

/**
 * @brief Macros to simplify usage of the log mManager
 */
#define LOG_INFO(__str__) spdlog::info("{} {}:{} {}", RELATIVE_FILE_PATH, __FUNCTION__, __LINE__, __str__);

#ifdef D_WINDOWS
#  define LOG_INFO_W(__str__)                                                                                                    \
    spdlog::info(                                                                                                                \
        L"{} {}:{} {}", utility::decodeFromUtf8(RELATIVE_FILE_PATH), utility::decodeFromUtf8(__FUNCTION__), __LINE__, __str__);
#else
#  define LOG_INFO_W(__str__) LOG_INFO(utility::encodeToUtf8(__str__));
#endif

#define LOG_WARNING(__str__) spdlog::warn("{} {}:{} {}", RELATIVE_FILE_PATH, __FUNCTION__, __LINE__, __str__);

#ifdef D_WINDOWS
#  define LOG_WARNING_W(__str__)                                                                                                 \
    spdlog::warn(                                                                                                                \
        L"{} {}:{} {}", utility::decodeFromUtf8(RELATIVE_FILE_PATH), utility::decodeFromUtf8(__FUNCTION__), __LINE__, __str__);
#else
#  define LOG_WARNING_W(__str__) LOG_WARNING(utility::encodeToUtf8(__str__));
#endif

#define LOG_ERROR(__str__) spdlog::error("{} {}:{} {}", RELATIVE_FILE_PATH, __FUNCTION__, __LINE__, __str__);

#ifdef D_WINDOWS
#  define LOG_ERROR_W(__str__)                                                                                                   \
    spdlog::error(                                                                                                               \
        L"{} {}:{} {}", utility::decodeFromUtf8(RELATIVE_FILE_PATH), utility::decodeFromUtf8(__FUNCTION__), __LINE__, __str__);
#else
#  define LOG_ERROR_W(__str__) LOG_ERROR(utility::encodeToUtf8(__str__));
#endif