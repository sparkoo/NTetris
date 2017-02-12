Name:           ntetris
Version:        1.0
Release:        1%{?dist}
Summary:        Simple tetris for command line

License:        MIT
URL:            https://github.com/sparkoo/NTetris
Source0:        https://github.com/sparkoo/NTetris/archive/1.0.tar.gz

BuildRequires:  ncurses-devel
Requires:       ncurses

%description
Ncurses-based simple tetris game for CLI gaming.

%prep
%setup -q -n NTetris-%{version}

%build
make clean
make CFLAGS="%{optflags}" all

%define  debug_package %{nil}

%install
mkdir -p %{buildroot}%{_bindir}
strip %{_builddir}/NTetris-1.0/build/ntetris
%{__install} -pm 0755 %{_builddir}/NTetris-1.0/build/ntetris %{buildroot}%{_bindir}/ntetris


%files
%doc README.md
%license LICENSE
%{_bindir}/ntetris


%changelog
* Wed Feb  8 2017 Michal Vala <mvala@redhat.com> 1.0-1
- initial version created many years ago as a school project
