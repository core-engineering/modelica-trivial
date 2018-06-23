#!/usr/bin/env bash

# Ajoute les sources openmodelica "nightly"
for deb in deb deb-src
do
  echo "$deb http://build.openmodelica.org/apt `lsb_release -cs` nightly"
done | sudo tee /etc/apt/sources.list.d/openmodelica.list

# Ajoute le certificat GPG
wget -q http://build.openmodelica.org/apt/openmodelica.asc -O- | sudo apt-key add -

# Vérifie le certificat GPG
apt-key fingerprint

# Installe OpenModelica
sudo apt update
sudo apt install openmodelica

# Installe OpenHydraulics
git clone https://github.com/cparedis/OpenHydraulics.git

# Installe OpenBLDC
git clone https://github.com/joewa/open-bldc-modelica.git
