%% plotUGD - script that loads and plots calculated UGD data

ugd = importdata( 'UGDMassless.txt' );

semilogx( ugd(:,1), ugd(:,2),...
          ugd(:,1),ugd(:,3),...
          ugd(:,1),ugd(:,4) );
legend( 'k� = 1', 'k� = 10', 'k� = 50' );
title( 'Unintegrated gluon density of photon (Q�=10)' );
xlabel( 'x' ); ylabel( 'UGD' );
grid on;