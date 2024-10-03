
function [duty_cycle] = power_increment_mppt(voltage, current, last_voltage, last_current, last_duty_cycle)
% Power Increment (Incremental Conductance) MPPT Algorithm
%
% Inputs:
%   voltage - Current PV voltage
%   current - Current PV current
%   last_voltage - Previous PV voltage
%   last_current - Previous PV current
%   last_duty_cycle - Previous duty cycle
%
% Output:
%   duty_cycle - New duty cycle for the converter

% Constants
DELTA_D = 0.01;  % Step size for duty cycle change

% Calculate changes
delta_V = voltage - last_voltage;
delta_I = current - last_current;

% Power Increment algorithm logic
if delta_V == 0
    if delta_I == 0
        duty_cycle = last_duty_cycle;  % At MPP
    elseif delta_I > 0
        duty_cycle = last_duty_cycle - DELTA_D;  % Left of MPP
    else
        duty_cycle = last_duty_cycle + DELTA_D;  % Right of MPP
    end
else
    if delta_I / delta_V == -current / voltage
        duty_cycle = last_duty_cycle;  % At MPP
    elseif delta_I / delta_V > -current / voltage
        duty_cycle = last_duty_cycle - DELTA_D;  % Left of MPP
    else
        duty_cycle = last_duty_cycle + DELTA_D;  % Right of MPP
    end
end

% Ensure duty cycle is within bounds [0, 1]
duty_cycle = max(0, min(1, duty_cycle));

end

% Example usage and simulation
% Initialize variables
voltage = 30;  % Initial PV voltage
current = 2;   % Initial PV current
last_voltage = 29;  % Previous PV voltage
last_current = 1.9;  % Previous PV current
last_duty_cycle = 0.5;  % Previous duty cycle

% Simulate panel behavior over time
time = 0:0.1:10;
voltage_array = zeros(size(time));
current_array = zeros(size(time));
duty_cycle_array = zeros(size(time));

for i = 1:length(time)
    % Simulate changing voltage and current (e.g., due to environmental conditions)
    voltage = 30 + 2*sin(time(i));
    current = 2 + 0.2*cos(time(i));
    
    % Run MPPT algorithm
    duty_cycle = power_increment_mppt(voltage, current, last_voltage, last_current, last_duty_cycle);
    
    % Store results
    voltage_array(i) = voltage;
    current_array(i) = current;
    duty_cycle_array(i) = duty_cycle;
    
    % Update last values for next iteration
    last_voltage = voltage;
    last_current = current;
    last_duty_cycle = duty_cycle;
end
