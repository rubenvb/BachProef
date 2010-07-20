%% plotFL - script to plot FL as in G-B thesis

FL = importdata( 'FL.txt' );
%FL(:,2:end)=FL(:,2:end).*pi/2; % arbitrary scale factor
plotopt = { '-r', '-b', '-k', '-c', '-y', '-g' };
figure( 'Name', 'FL', 'NumberTitle', 'Off' );
semilogx( FL(:,1),FL(:,2), ...
          FL(:,1),FL(:,3), ...
          FL(:,1),FL(:,4), ...
          FL(:,1),FL(:,5), ...
          FL(:,1),FL(:,6), ...
          FL(:,1),FL(:,7) );
grid on;axis( [1e-4 1e-1 -.5 1.5 ] );
xlabel( 'x' ); ylabel( 'FL' );
legend( 'Q�=24', 'Q�=32', 'Q�=45', 'Q�=60', 'Q�=80', 'Q�=110' );
