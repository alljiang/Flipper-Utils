
import re
import sys
import math
import matplotlib.pyplot as plt

filename = 'sumedh_garage.sub'


data = []
with open(filename, 'r') as f:
    for line in f:
        m = re.match(r'RAW_Data:\s*([-0-9 ]+)\s*$', line)

        if m:
            data.extend([ int(seg) for seg in m[1].split(r' ') if seg != ''])

accumulated_time = 0
absolute_times = []
bit_values = []

for time_interval in data:
    absolute_times.append(accumulated_time)
    accumulated_time += abs(time_interval)

    if time_interval > 0:
        bit_values.append(1)
    else:
        bit_values.append(0)

plt.plot(absolute_times, bit_values)
plt.show()
