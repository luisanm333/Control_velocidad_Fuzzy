function[con1 con2 con3 con4 con5]=Funcion_con_fuzz (dato,a1, d1, a2, d2, a3, d3, a4, d4, a5)%'dato' de entrada

Distancia_cm=dato;

  con1=exp((-(Distancia_cm-a1)^2)/(2*(d1^2)));
  con2=exp((-(Distancia_cm-a2)^2)/(2*(d2^2)));
  con3=exp((-(Distancia_cm-a3)^2)/(2*(d3^2)));
  con4=exp((-(Distancia_cm-a4)^2)/(2*(d4^2)));
  con5=1/(1+exp(-0.3*(Distancia_cm-a5)));

if (Distancia_cm>7 & Distancia_cm<15)
    con1=0;
    con2=exp((-(Distancia_cm-a2)^2)/(2*(d2^2)));
    con3=0;
    con4=0;
    con5=0;
end

