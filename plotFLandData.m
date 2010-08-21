%% PlotFLandData - plots my FL calculations vs HERA Data and other
%    calculations

load( 'FLData.mat' ); % load H1 data points
FLMassive = importdata( 'FLMassive.txt' ); % load my Massive FL
FLMassless = importdata( 'FLMassless.txt' ); % load my Massless FL
figure( 'Name', 'F_L, Q²=12', 'NumberTitle', 'Off' );
    % my calculations
    semilogx( FLMassless(:,1), FLMassless(:,2), '-b' );
    hold on;
    semilogx( FLMassive(:,1), FLMassive(:,2), '-r' );
    % dummy entry for legend entry other line
    semilogx( -1, -1, '--k' ); 
    % H1 Data
    errorbar( FLH1Q12(1), FLH1Q12(2), FLH1Q12(3), 'dg' );
    %title( 'Q²=12' );
    axis( [1e-4 1e-1 0 1.5] );
    xlabel( 'x' ); ylabel( 'F_L' );
    grid on;
    hold off;

figure( 'Name', 'F_L, Q²=15', 'NumberTitle', 'Off' );
    % my calculations
    semilogx( FLMassless(:,1), FLMassless(:,3), '-b' );
    hold on;
    semilogx( FLMassive(:,1), FLMassive(:,3), '-r' );
    % dummy value for legend entry other line
    semilogx( -1,-1, '--k' );
    % H1
    errorbar( FLH1Q15(1), FLH1Q15(2), FLH1Q15(3), 'dg' ); 
    %title( 'Q²=15' );
    axis( [1e-4 1e-1 0 1.5] );
    xlabel( 'x' ); ylabel( 'F_L' );
    grid on;
    hold off;
    
figure( 'Name', 'F_L, Q²=20', 'NumberTitle', 'Off' );
    % my calculations
    semilogx( FLMassless(:,1), FLMassless(:,4), '-b' );
    hold on;
    semilogx( FLMassive(:,1), FLMassive(:,4), '-r' );
    % dummy data for legend entry other line
    semilogx( -1, -1, '--k' );
    % Zeus
    errorbar( FLH1Q20(1), FLH1Q20(2), FLH1Q20(3), 'dg' ); 
    %title( 'Q²= 20' );
    axis( [1e-4 1e-1 0 1.5] );
    xlabel( 'x' ); ylabel( 'F_L' );
    legend( 'GBW zonder charm', 'GBW met charm', ...
            'DGLAP/BFKL zonder saturatie', ...
            'H1 data' );
    grid on;
    hold off;
    
figure( 'Name', 'F_L, Q²=25', 'NumberTitle', 'Off' );
    % my calculations
    semilogx( FLMassless(:,1), FLMassless(:,5), '-b' );
    hold on;
    semilogx( FLMassive(:,1), FLMassive(:,5), '-r' );
    % dummy data for legend entry other line
    semilogx( -1, -1, '--k' );
    % Zeus
    errorbar( FLH1Q25(1), FLH1Q25(2), FLH1Q25(3), 'dg' ); 
    %title( 'Q²=25' );
    axis( [1e-4 1e-1 0 1.5] );
    xlabel( 'x' ); ylabel( 'F_L' );
    grid on;
    hold off;
    
%% cleanup
clear FLH1Q12 FLH1Q15 FLH1Q20 FLH1Q25 FLMassive FLMassless;
