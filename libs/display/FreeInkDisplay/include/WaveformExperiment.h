#pragma once

#include <cstddef>
#include <cstdint>

namespace freeink {

// Waveform experiments (host tools): runtime replacements for a driver's
// waveform tables, so candidates can be tried without reflashing.
// Overlay = the gray anti-aliasing pass, Settle = the non-flashing B/W
// transition before it, Direct = the single-pass four-tone refresh.
enum class ExperimentBank : uint8_t { Overlay = 0, Settle = 1, Direct = 2 };

// Phase timings of one panel refresh.
struct RefreshTimings {
  const char* pass = nullptr;  // "gray", "direct", "settle"; null when unused
  uint32_t streamUs = 0;       // plane uploads since the previous refresh
  uint32_t lutUs = 0;
  uint32_t powerOnUs = 0;
  uint32_t refreshUs = 0;  // DRF until BUSY clears: the waveform itself
  uint32_t powerOffUs = 0;
  uint32_t totalUs = 0;
  uint32_t atMs = 0;
};

}  // namespace freeink
