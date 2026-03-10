# Calibration Guide

## Why Calibration Matters

Battery voltage readings are only as good as the assumptions used in the monitoring circuit. The Arduino estimate depends on:

- actual Arduino reference voltage
- resistor tolerance in the voltage divider
- wiring stability
- battery condition
- ADC noise

## Voltage Divider

If two equal resistors are used, such as 100kΩ and 100kΩ, the divider ratio is approximately 2.0.

Example:

- Battery voltage: `4.2V`
- Arduino sees: `2.1V`

## Procedure

1. Measure actual battery voltage with a multimeter
2. Read the Arduino-reported battery voltage in the Serial Monitor
3. Compare the two values
4. If needed, adjust:
   - `referenceVoltage`
   - `voltageDividerRatio`
5. Repeat until the Arduino estimate is acceptably close

## Example Battery Thresholds

- Full: `4.15V`
- Normal: `3.70V` and above
- Low: `3.40V`
- Critical: below `3.40V`

## Notes

- Reference voltage may not be exactly 5.0V
- Resistors may differ slightly from nominal value
- Always validate measurements against a multimeter
- Recalibrate if resistor values or wiring change
