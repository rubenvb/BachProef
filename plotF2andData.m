%% PlotF2andData - plots my F2 calculations vs HERA Data and other
%    calculations

load( 'F2Data.mat' ); % load ZEUS data points
F2Massive = importdata( 'F2Massive.txt' ); % load my Massive F2
F2Massless = importdata( 'F2Massless.txt' ); % load my Massless F2
figure( 'Name', 'F_2, Q²=24', 'NumberTitle', 'Off' );
    % my calculations
    semilogx( F2Massless(:,1), F2Massless(:,2), '-b' );
    hold on;
    semilogx( F2Massive(:,1), F2Massive(:,2), '-r' );
    % ZEUS Data
    errorbar( F2ZEUSQ24(:,1), F2ZEUSQ24(:,2), F2ZEUSQ24(:,3), F2ZEUSQ24(:,4), 'dg' );
    %title( 'Q²=12' );
    axis( [1e-4 1e-1 0 1.5] );
    xlabel( 'x' ); ylabel( 'F_2' );
    grid on;
    hold off;

figure( 'Name', 'F_2, Q²=32', 'NumberTitle', 'Off' );
    % my calculations
    semilogx( F2Massless(:,1), F2Massless(:,3), '-b' );
    hold on;
    semilogx( F2Massive(:,1), F2Massive(:,3), '-r' );
    % dummy value for legend entry other line
    semilogx( -1,-1, '--k' );
    % ZEUS
    errorbar( F2ZEUSQ32(:,1), F2ZEUSQ32(:,2), F2ZEUSQ32(:,3), F2ZEUSQ32(:,4), 'dg' ); 
    %title( 'Q²=15' );
    axis( [1e-4 1e-1 0 1.5] );
    xlabel( 'x' ); ylabel( 'F_2' );
    legend( 'GBW zonder charm', 'GBW met charm', ...
            'ZEUS data' );
    grid on;
    hold off;
    
figure( 'Name', 'F_2, Q²=45', 'NumberTitle', 'Off' );
    % my calculations
    semilogx( F2Massless(:,1), F2Massless(:,4), '-b' );
    hold on;
    semilogx( F2Massive(:,1), F2Massive(:,4), '-r' );
    % dummy data for legend entry other line
    semilogx( -1, -1, '--k' );
    % Zeus
    errorbar( F2ZEUSQ45(:,1), F2ZEUSQ45(:,2), F2ZEUSQ45(:,3), F2ZEUSQ45(:,4), 'dg' ); 
    %title( 'Q²= 20' );
    axis( [1e-4 1e-1 0 1.5] );
    xlabel( 'x' ); ylabel( 'F_2' );
    grid on;
    hold off;
    
%% cleanup
clear F2Massless F2Massive F2ZEUSQ24 F2ZEUSQ32 F2ZEUSQ45;
