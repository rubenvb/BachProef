%% plotET - script that loads calculated ET data and creates nice plots.

%ET = importdata( 'ETAlt.txt' ); % load my E_T
%ET2 = importdata( 'ETAlt2.txt' ); % second run
load( 'ETData.mat' );

figure( 'Name', 'E_T, Q²=10', 'NumberTitle', 'Off' );
    semilogx( ...%ET(:,1), ET(:,2), ...
              ET(:,1), ET(:,3), '-r', ...
              ET(:,1), ET(:,4), '-g', ...
              ET(:,1), ET(:,5), '-k' );
    hold on;
    % dummy data for three extra lines.
    plot( -1, -1, 'color', [153, 139, 61]./255 );
    plot( -1, -1, 'color', [153, 61, 113]./255 );
    plot( -1, -1, 'color', [63, 61, 153]./255 );
    xlabel( '$x_j$', 'interpreter', 'latex' );
    ylabel( '$x_j \frac{\partial E_T}{\partial x_j}$','Interpreter','LaTex' );
    axis( [1e-7, 1e-1, 0, 35] );
    l = legend( '$x=10^{-6}$', ...
                '$x=10^{-5}$', ...
                '$x=10^{-4}$', ...
                '$x=10^{-6}$ (analytisch)', ...
                '$x=10^{-5}$ (analytisch)', ...
                '$x=10^{-4}$ (analytisch)' );
    set( l, 'interpreter', 'latex' );
    title( 'Transversale energiestroom' );
    hold off;

%% cleanup
clear ET ET2 l;