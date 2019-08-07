bruteForceData = importdata("10000bruteForce.txt");
customMethodData = importdata("3000customMethod.txt");
fermatDataX = linspace(0, 10000, 10000);
fermatDataY = fermatDataX * 0.00001;
plot(bruteForceData(:,1), bruteForceData(:,2), 'Blue');
hold on
plot(customMethodData(:,1), customMethodData(:,2), 'Red');
plot(fermatDataX, fermatDataY, 'Green');
ylim([0,1.2])
title('Time Analytics for Various Primality Algorithms')
xlabel('N = maximum number of primes generated') 
ylabel('Time') 
legend('Brute Force','Smart Brute Force', 'Fermat')