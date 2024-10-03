
function [duty_cycle, power] = perturb_and_observe(voltage, current, last_voltage, last_power, last_duty_cycle)
% Perturb and Observe MPPT Algorithm
%
% Inputs:
%   voltage - Current PV voltage
%   current - Current PV current
%   last_voltage - Previous PV voltage
%   last_power - Previous PV power
%   last_duty_cycle - Previous duty cycle
%
% Outputs:
%   duty_cycle - New duty cycle
%   power - Current PV power

% Constants
DELTA_D = 0.01;  % Step size for duty cycle change

% Calculate current power
power = voltage * current;

% Calculate change in power
delta_P = power - last_power;
delta_V = voltage - last_voltage;

% P&O algorithm logic
if delta_P ~= 0
    if delta_P > 0
        if delta_V > 0
            duty_cycle = last_duty_cycle + DELTA_D;
        else
            duty_cycle = last_duty_cycle - DELTA_D;
        end
    else
        if delta_V > 0
            duty_cycle = last_duty_cycle - DELTA_D;
        else
            duty_cycle = last_duty_cycle + DELTA_D;
        end
    end
else
    duty_cycle = last_duty_cycle;
end

% Ensure duty cycle is within bounds [0, 1]
duty_cycle = max(0, min(1, duty_cycle));

end

% Example usage:
% Initialize variables
voltage = 30;  % Current PV voltage
current = 2;   % Current PV current
last_voltage = 29;  % Previous PV voltage
last_power = 55;    % Previous PV power
last_duty_cycle = 0.5;  % Previous duty cycle

% Run P&O algorithm
[new_duty_cycle, new_power] = perturb_and_observe(voltage, current, last_voltage, last_power, last_duty_cycle);

% Display results
fprintf('New duty cycle: %.4f\n', new_duty_cycle);
fprintf('New power: %.2f W\n', new_power);
