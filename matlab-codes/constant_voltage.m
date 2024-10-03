function [duty_cycle] = constant_voltage_mppt(voltage, v_oc, v_ref_ratio, v_in)
% Constant Voltage MPPT Algorithm
%
% Inputs:
%   voltage - Current PV voltage
%   v_oc - Open circuit voltage of the PV panel
%   v_ref_ratio - Ratio of MPP voltage to open circuit voltage (typically 0.71 to 0.78)
%   v_in - Input voltage of the converter
%
% Output:
%   duty_cycle - New duty cycle for the converter

% Calculate reference voltage
v_ref = v_oc * v_ref_ratio;

% Calculate error
error = v_ref - voltage;

% Calculate duty cycle
% Assuming a buck converter: Vout = D * Vin
% We want Vout to be v_ref, so D = v_ref / v_in
duty_cycle = v_ref / v_in;

% Ensure duty cycle is within bounds [0, 1]
duty_cycle = max(0, min(1, duty_cycle));

end

% Example usage:
% Initialize variables
voltage = 30;      % Current PV voltage
v_oc = 42;         % Open circuit voltage
v_ref_ratio = 0.76; % MPP voltage ratio (can be adjusted based on panel characteristics)
v_in = 42;         % Input voltage of the converter (usually equal to v_oc for MPPT)

% Run Constant Voltage MPPT algorithm
new_duty_cycle = constant_voltage_mppt(voltage, v_oc, v_ref_ratio, v_in);

% Display result
fprintf('New duty cycle: %.4f\n', new_duty_cycle);

% Simulate panel behavior over time
time = 0:0.1:10;
voltage_array = zeros(size(time));
duty_cycle_array = zeros(size(time));

for i = 1:length(time)
    % Simulate changing voltage (e.g., due to environmental conditions)
    voltage = 30 + 2*sin(time(i));
    
    % Run MPPT algorithm
    duty_cycle = constant_voltage_mppt(voltage, v_oc, v_ref_ratio, v_in);
    
    % Store results
    voltage_array(i) = voltage;
    duty_cycle_array(i) = duty_cycle;
end
