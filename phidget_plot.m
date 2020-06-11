clear
clc

plotTitle = 'Phidget Plot';  
xLabel = 'Elapsed Time (s)';     
yLabel = 'Sensor Value';      
legendName = 'Sensor';

yMax  = 1;                         
yMin  = 0;   

plotGrid = 'on';               
min = -1;                      
max = 1;   

delay = .01;                    
time = 0;

data = 0;
count = 0;

plotGraph = plot(time,data,'-r' );
title(plotTitle,'FontSize',15);
xlabel(xLabel,'FontSize',15);
ylabel(yLabel,'FontSize',15);
legend(legendName)
axis([yMin yMax min max]);
grid(plotGrid);
tic

while ishandle(plotGraph) 
    phidget = phidgetBridge*10000; %just multiplying to make it easier to plot, not calibrated    
    count = count + 1;    
    time(count) = toc;    
    data(count) = phidget(1);         
    set(plotGraph,'XData',time,'YData',data);
    axis([0 time(count) min max]);
    pause(delay);
end