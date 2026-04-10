# Copilot Instructions for RedBox Library

This repository is an Arduino C++ library for I2C communication.

## Goals

- Implement a small, reusable Arduino library for I2C devices.
- Keep the public API simple for Arduino sketches.
- Prefer code that works on common Arduino targets using the standard `Wire` library.
- Keep the code easy to read, easy to test in examples, and easy to extend for additional registers or commands.

## Project Conventions

- Put library headers in `src/` and keep implementation in matching `.cpp` files.
- Use Arduino library conventions so the project works with the Arduino IDE and PlatformIO without special setup.
- Keep the main public header lightweight and include only what is needed.
- Match file names and public class names consistently.
- Update `README.md`, `library.properties`, and `examples/` when public behavior changes.

## C++ Style

- Use Stroustrup style for braces and indentation.
- When functions and classes are declared prefix parentheses with a single space, e.g. `void foo ()`.  When functions are called the parentheses should not be prefixed with a space, e.g. `foo()`.
- Write modern, straightforward C++ that is compatible with typical Arduino toolchains.
- Prefer small classes with explicit responsibilities.
- Avoid dynamic allocation unless there is a clear need.
- Avoid exceptions, RTTI-heavy patterns, and unnecessary template complexity.
- Prefer fixed-width integer types like `uint8_t`, `uint16_t`, and `uint32_t` for register and buffer work.
- Use `const` correctness for parameters and methods where it improves API clarity.
- Keep RAM usage low; move constant strings or tables out of RAM when practical.

## Arduino and I2C Guidance

- Use the standard `Wire` library for I2C communication unless the user explicitly asks for an alternative.
- Expose `begin()` style initialization that makes bus setup obvious.
- Allow the I2C address to be configured when reasonable.
- Provide clear helpers for common operations such as:
  - writing a register
  - reading a register
  - reading multiple bytes
  - checking transmission status
- Handle I2C errors explicitly and return useful status values instead of hiding failures.
- Respect common Arduino patterns: non-blocking where practical, short methods, and predictable side effects.
- Avoid hard-coding board-specific pins or assumptions unless the user requests a specific board.

## API Design

- Design the library around the device behavior, not around raw `Wire` calls alone.
- Public methods should express intent, for example `readTemperature()` or `setMode(...)`, when the target device behavior is known.
- Keep low-level helpers private unless there is a strong reason to expose them.
- Prefer returning a status code or `bool` and writing outputs through references for operations that can fail.
- Document units, valid ranges, and default values in header comments when they are important to correct use.

## Examples and Documentation

- Add or update example sketches in `examples/` for any meaningful public API.
- Keep examples minimal, compilable, and focused on one use case each.
- Show typical Arduino setup and loop usage.
- Update `README.md` with:
  - what the library does
  - supported hardware assumptions
  - installation notes if needed
  - a short usage example

## Implementation Expectations

- Favor small helper functions for repeated register access logic.
- Validate buffer sizes and edge cases before reading or writing on the bus.
- Preserve backward compatibility when modifying existing public APIs unless the user asks for a breaking change.
- Do not introduce extra dependencies unless they materially improve the library and fit Arduino environments.
- Keep compile-time portability in mind across AVR, SAMD, ESP32, and similar Arduino-supported targets.

## When Copilot Makes Changes

- If adding a new device feature, update the public header, implementation, at least one example, and the README when needed.
- If adding new constants or registers, group and name them clearly.
- If an operation can fail on the I2C bus, surface that failure in the API.
- Prefer targeted edits over broad rewrites.
- Preserve the existing style and library structure unless the user asks for a refactor.

