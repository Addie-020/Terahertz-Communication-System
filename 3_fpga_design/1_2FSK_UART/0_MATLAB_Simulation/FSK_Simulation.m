M = 2;              % Modulation order
freqsep = 8000000;  % Frequency separarion (Hz)
nsamp = 8;          % Number of samples per symbol
Fs = 32000000;      % Sample rate (Hz)

% Generate random M-ary symbols
x = randi([0 M-1], 1000, 1);

% Apply FSK modulation
y = fskmod(x, M, freqsep, nsamp, Fs, 'cont');

specAnal = dsp.SpectrumAnalyzer('SampleRate',Fs);
specAnal(y);