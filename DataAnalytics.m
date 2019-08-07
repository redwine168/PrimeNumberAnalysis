bruteForceData = importdata("bruteForce.txt");
smartBruteForceData = importdata("smartBruteForce.txt");
%fermatDataX = linspace(0, 10000, 10000);
%fermatDataY = fermatDataX * 0.00001;
plot(bruteForceData(:,1), bruteForceData(:,2), 'Blue');
hold on
plot(smartBruteForceData(:,1), smartBruteForceData(:,2), 'Red');
%plot(fermatDataX, fermatDataY, 'Green');
title('Time Analytics for Various Primality Algorithms')
xlabel('N = maximum number of primes generated') 
ylabel('Time') 
legend('Brute Force','Smart Brute Force')