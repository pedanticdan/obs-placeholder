/*
obs-placeholder
*/

#pragma once

#include <obs.hpp>

#define OBS_PLACEHOLDER_VERSION "0.0.3"

#define blog(level, msg, ...) blog(level, "[obs-placeholder] " msg, ##__VA_ARGS__)
