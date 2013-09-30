Summary: von-Neumann-Emulator
Name: emulator
Version: 1.0rc6
Release: 1
License: GPL
Group: Applications/Emulator
URL: https://trac.gathered-geeks.org/emulator/

Source0: http://pool.funzi.org/emulator/releases/emulator-%{version}.tar.gz

Requires: qt >= 4.4

BuildRequires: qt-devel >= 4.4
BuildRequires: gcc-c++
BuildRequires: make

%description
von-Neumann-Emulator zur Verwendung an der Justus-Liebig-Universität Gießen.

%prep
%setup -q

%build
qmake-qt4
%{__make}
strip --strip-all emulator

%install
%{__mkdir} -p "$RPM_BUILD_ROOT/usr/local/bin"
%{__cp} emulator "$RPM_BUILD_ROOT/usr/local/bin"

%clean
%{__make} clean

%files
%attr(755, root, root) /usr/local/bin/emulator
