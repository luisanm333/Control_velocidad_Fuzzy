clc, close all, clear all;

a1=0; d1=3; a2=10; d2=4; a3=25; d3=4; a4=50; d4=8; a5=70; 
s1=100; s2=0; s3=50; s4=80; s5=180;
k=0;
for gris =0:100
    [c1 c2 c3 c4 c5 ] = Funcion_con_fuzzy(gris,a1, d1, a2, d2, a3, d3, a4, d4, a5);
    k = k+1;
    con1(k)=c1;
    con2(k)=c2;
    con3(k)=c3;
    con4(k)=c4;
    con5(k)=c5;

    
    pwm(k)=((c1*s1)+(c2*s2)+(c3*s3)+(c4*s4)+(c5*s5))/(c1+c2+c3+c4+c5);
end

distancia=0:100;
plot(distancia,pwm*100/255);

figure, hold on, plot(con1,'r'),plot(con2,'b'),plot(con3,'g'), plot(con4,'m'), plot(con5,'k'),hold off