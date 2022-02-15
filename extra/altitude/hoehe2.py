import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

#http://walter.bislins.ch/aviatik/index.asp?page=Barometrische+H%F6henformel&head=#H_Rechenformular

# Definition der Konstanten

To = 288.15		# Referenz-Temperatur
po = 1013.25	# Referenz-Luftdruck
g = 9.80665	    # Erdbeschleunigung
M = 0.0289644 	# Molare Masse trockene Luft
R = 8.314462618 # Universelle Gaskonstante
RsL = 287.058   # Spezifische Gaskonstante trockene Luft
ho = 0	        # Referenz-Höhe

Rsh = 2077.1    # Spezifische Gaskonstante Helium

Mo = 1700.0     # Masse Wetterballon
mo = 1.5	    # Masse Helium-Gas

# Steigungen der Kelvin pro Meter
aref = -0.0065
aref2 = 0.0
Tref = 216.65 	# Referenz-Temperatur zwischen 11 und 20 km Höhe
pref = 226.321  # Referenz-Druck zwischen 11 und 20 km Höhe

rhoH = 0.1787 	# Dichte Helium kg/m³
rhoL = 1.1455 	# Dichte Luft kg/m³'

#Definition Daten

xkoord=[]; ykoord=[]; zkoord=[]; tkoord=[]
F = []
va = []



# Berechnung


def drueck(h):
	if h <= 11000:
		beta = g/(RsL*aref)
		p = po * (1 + (aref*(h-ho))/(To) )**(-beta)
		t = To + aref*(h-ho)
		rho = 1225.0 * (1 + ((aref*(h-ho))/(To)))**(-beta - 1)


	elif (11000 < h <= 20000):
		hs = RsL*Tref/(g)
		p = pref*np.exp(-(h-11000)/hs)
		t = Tref + aref2*(h-11000)
		rho = 363.918 * np.exp(-(h-11000)/hs)

	elif (20000 < h <= 32000):
		beta = g/(RsL*0.001)
		p = 54.7489 * (1 + (0.001*(h-20000))/(Tref) )**(-beta)
		t = Tref + 0.001*(h-20000)
		rho = 88.0348 * (1 + ((0.001*(h-20000))/(Tref)))**(-beta - 1)

	elif (32000 < h <= 47000):
		beta = g/(RsL*0.0028)
		p = 8.68019 * (1 + (0.0028*(h-32000))/(228.65) )**(-beta)
		t = 228.65 + 0.0028*(h-32000)
		rho = 13.2250 * (1 + ((0.0028*(h-32000))/(228.65)))**(-beta - 1)

	elif (47000 < h <= 51000):
		#beta = g/(RsL*0.0)
		p = 1.10906 * (1 + (0.0*(h-47000))/(270.65) )
		t = 270.65 + 0.0*(h-47000)
		rho = 1.42753 * (1 + ((0.0*(h-47000))/(270.65)))**(-1)

	elif (51000 < h <= 71000):
		beta = g/(RsL*(-0.0028))
		p = 0.669389 * (1 + ((-0.0028)*(h-51000))/(270.65) )**(-beta)
		t = 270.65 + (-0.0028)*(h-51000)
		rho = 0.861605 * (1 + (((-0.0028)*(h-51000))/(270.65)))**(-beta - 1)

	elif (71000 < h <= 84852):
		beta = g/(RsL*(-0.002))
		p = 0.0395642 * (1 + ((-0.002)*(h-71000))/(214.65) )**(-beta)
		t = 214.65 + (-0.002)*(h-71000)
		rho = 0.0642110 * (1 + (((-0.002)*(h-71000))/(214.65)))**(-beta - 1)

	#return [p, rho] # brackets!!!!!! return a list!!!!!!!!!!!!!
	return [p, rho, t];
	#return p, rho;


def heli(h):
	beta = g/(Rsh*aref)
	#p = po * (1 + (aref*(h-ho))/(To) )**(-beta)
	rho = rhoH * (1 + ((aref*(h-ho))/(To)))**(-beta - 1)

	return rho

#b = 0

ykoord = np.linspace(1,81500,81500)

for i in range(0, len(ykoord)):
	#xkoord.append(drueck(ykoord[i]))
	#[xkoord[i], zkoord[i]] = drueck(ykoord[i])
	a = drueck(ykoord[i])
	xkoord.append(a[0])
	zkoord.append(a[1])
	tkoord.append(a[2])
	new = (rhoH/rhoL)*(a[1]/1000)
	new2 = (a[1]/1000)/rhoL
	F.append((mo/new)*((rhoL-rhoH)*new2))
	f = (mo/new)*((rhoL-rhoH)*new2)
	va.append(np.sqrt((f*g)/(0.25*a[1]/1000)))


# Berechnung des Auftriebs

#for i in range(0, len(h)):
#	F.append(drueck(h[i]))
#	rho2[0,i] = heli(h[i])
	#F.append((mo/rho2[0,i]) * (rhoL-rhoH))

plt.figure()
plt.subplot(1,2,1)
plt.plot(xkoord,ykoord, 'g-', label='Druck')
plt.plot(zkoord,ykoord, 'r-', label='Dichte')
plt.plot(tkoord,ykoord, 'k-', label='Auftrieb')
plt.ylabel('Hoehe in [m]')
plt.xlabel('Werte')
plt.grid()

plt.subplot(1,2,2)
plt.plot(F,ykoord, 'c-')
plt.plot(va,ykoord, 'r-')
plt.axis([0,110, 0, 80000])  # Achsengrenzen festsetzen xmin, xmax, ymin, ymax
#plt.plot(F,h, 'g-')
plt.grid()
plt.legend()
plt.show()

