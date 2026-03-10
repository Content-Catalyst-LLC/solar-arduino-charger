# Solar Arduino Charger

A solar-powered Arduino charger prototype that demonstrates decentralized renewable energy generation, storage, regulation, and monitoring.

This project is designed as a reproducible prototype for engineers, students, and researchers interested in small-scale solar power systems, embedded monitoring, and sustainable energy infrastructure.

## Overview

The system combines four core functions:

- solar energy generation through a photovoltaic panel
- battery charging through a TP4056 charge controller
- voltage regulation through a 5V boost converter
- battery monitoring through an Arduino voltage-sensing circuit

At a systems level, the architecture can be summarized as:

Solar Panel → Charge Controller → Battery → Boost Converter → Load

The monitoring path is:

Battery → Voltage Divider → Arduino ADC → Status Logic → Serial / LEDs

## Features

- photovoltaic energy capture
- lithium-ion battery storage
- 5V regulated output
- battery voltage monitoring
- sample averaging for more stable readings
- battery status classification
- optional LED indicators
- extensible for displays, logging, or telemetry

## Repository Structure

- `firmware/` — Arduino monitoring firmware
- `docs/` — setup and calibration documentation
- `data/` — example battery readings
- `hardware/` — wiring diagrams and schematics
- `BOM.csv` — bill of materials

## Hardware

- Arduino Uno or Nano
- 6V–9V solar panel
- 18650 lithium-ion battery
- TP4056 charging module with protection
- DC boost converter set to 5V
- USB output module or breakout
- resistor divider for voltage sensing
- jumper wires and breadboard or PCB

## Notes

This is a prototype reference design, not a certified consumer charging device. Engineers adapting it for extended use should validate:

- charge controller limits
- battery quality and protection
- thermal behavior
- output voltage stability
- enclosure protection
- long-term electrical reliability

## License

This project is released under the MIT License.

See `LICENSE` for details.
