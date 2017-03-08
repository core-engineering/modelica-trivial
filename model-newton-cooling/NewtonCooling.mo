model NewtonCooling "Cooling example with physical units"
    type Temperature = Real(unit="K",min=0);
    type ConvectionCoefficient = Real(unit="W/(m2.K)",min=0);
    type Area = Real(unit="m2",min=0);
    type Mass = Real(unit="kg",min=0);
    type SpecificHeat = Real(unit="J/(K.kg)",min=0);
    
    parameter Temperature T_inf = 298.15 "Ambient temperature";
    parameter Temperature T_0 = 363.15 " Initial temperature";
    parameter ConvectionCoefficient h = 0.7 "Convective cooling coefficient";
    parameter Area A = 1.0 "Surface area";
    parameter Mass m = 0.1 "Mass of thermal capacitance";
    parameter SpecificHeat c_p = 1.2 "Specific heat";

    Temperature T(unit="K") "Temperature";

initial equation
    T = T_0 "Specify initial value for T";

equation
    m*c_p*der(T) = h*A*(T_inf-T) "Newton's law of cooling";
    annotation(experiment(StartTime=0,StopTime=8));
end NewtonCooling;
