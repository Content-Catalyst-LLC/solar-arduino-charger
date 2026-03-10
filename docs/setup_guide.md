# Setup Guide

## Purpose

This guide explains how to assemble and test the Solar Arduino Charger prototype.

## Wiring Overview

### Solar Charging Circuit

- Solar Panel + → TP4056 IN+
- Solar Panel – → TP4056 IN–
- Battery + → TP4056 B+
- Battery – → TP4056 B–

### Power Output Circuit

- TP4056 OUT+ → Boost Converter IN+
- TP4056 OUT– → Boost Converter IN–
- Boost Converter OUT+ → USB 5V
- Boost Converter OUT– → USB GND

### Arduino Monitoring Circuit

- Battery positive line → voltage divider → Arduino A0
- Battery ground → Arduino GND

## Build Steps

1. Connect the solar panel to the TP4056 input terminals
2. Connect the 18650 battery to the TP4056 battery terminals
3. Connect the TP4056 output to the boost converter input
4. Verify the boost converter output is approximately 5V using a multimeter
5. Build the voltage divider and connect its midpoint to Arduino A0
6. Upload `solar_charger_monitor.ino` to the Arduino
7. Open the Serial Monitor at `9600` baud
8. Place the panel in sunlight and observe battery readings

## Safety Notes

- Do not connect a lithium battery directly to a solar panel
- Use a TP4056 module with protection whenever possible
- Verify boost converter output before connecting a device
- Keep battery terminals insulated
- Do not expose the prototype to rain or high heat without proper enclosure
- This is an educational prototype, not a certified consumer charger

## Validation

Before relying on the prototype, verify:

- the solar panel produces useful input voltage in sunlight
- the TP4056 is operating within expected limits
- the boost converter is outputting a stable 5V
- Arduino battery readings roughly match a multimeter
- the battery status labels correspond to measured voltage
