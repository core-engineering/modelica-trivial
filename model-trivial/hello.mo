model Hello "A differential equation"
  Real x(start=2);
equation
  der(x)=-x;
  annotation(experiment(StartTime=0,StopTime=8));
end Hello;
