/*
 * Copyright (c) 2020, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#pragma once
#include <chrono>

#ifdef __DOXYGEN__

namespace modm
{

/**
 * Spin for nanoseconds.
 *
 * @warning This function is implemented as best-effort and its resolution will
 *          be very coarse especially on platforms with very slow clocks.
 *
 * @warning The maximum delay is less than 1 millisecond.
 *
 * @note In debug mode this function may raise "delay.us" if input validation
 *       fails.
 *
 * @ingroup modm_architecture_delay
 */
void delay(std::chrono::nanoseconds ns);
/// @ingroup modm_architecture_delay
void delay_ns(uint32_t ns);

/**
 * Is true if nanosecond delay is reasonably accurate.
 * On devices with low clock speed it may not be possible to provide this
 * function with <100ns or even <1000ns accuracy.
 *
 * @ingroup modm_architecture_delay
 */
#define MODM_DELAY_NS_IS_ACCURATE bool(true or false)

/**
 * Spin for microseconds.
 *
 * @warning The maximum delay is less than 10 seconds.
 *
 * @note In debug mode this function may raise "delay.us" if input validation
 *       fails.
 *
 * @ingroup modm_architecture_delay
 */
void delay(std::chrono::microseconds us);
/// @ingroup modm_architecture_delay
void delay_us(uint32_t us);

/**
 * Spin for milliseconds.
 *
 * @warning The maximum delay is less than 10 seconds.
 *
 * @note In debug mode this function may raise "delay.us" if input validation
 *       fails.
 *
 * @ingroup modm_architecture_delay
 */
void delay(std::chrono::milliseconds ms);
/// @ingroup modm_architecture_delay
void delay_ms(uint32_t ms);

}

#else

// These functions may be implemented as header files, so we cannot rely on
// there being a link-able function and delegate this choice to the platform.
#include <modm/platform/core/delay_impl.hpp>

namespace modm
{

// Everything else is cast to microseconds
template<class Rep, class Period>
inline void delay(std::chrono::duration<Rep, Period> time)
{ delay(std::chrono::duration_cast<std::chrono::microseconds>(time)); }

// The old methods are deprecated
[[deprecated("Use `modm::delay_ns(uint32_t ns)` instead!")]]
inline void delayNanoseconds(uint32_t ns) { delay_ns(ns); }

[[deprecated("Use `modm::delay_us(uint32_t us)` instead!")]]
inline void delayMicroseconds(uint32_t us) { delay_us(us); }

[[deprecated("Use `modm::delay_ms(uint32_t ms)` instead!")]]
inline void delayMilliseconds(uint32_t ms) { delay_ms(ms); }

} // namespace modm

#endif

