Name:           ntetris
Version:        1.0
Release:        1%{?dist}
Summary:        Simple tetris for command line
Summary(cs):    Jednoduchá hra tetris pro terminál

License:        MIT
URL:            https://github.com/sparkoo/NTetris
Source0:        https://github.com/sparkoo/NTetris/archive/1.0.tar.gz

BuildRequires:  ncurses-devel
Requires:       ncurses

%description
Ncurses-based simple tetris game for CLI gaming.

%description -l cs
Jednoduchá hra tetris postavená na knihovně ncurses pro hraní v terminálu.

%prep
%setup -q -n NTetris-%{version}

%build
make clean
export CFLAGS="%{optflags}"
export LDFLAGS="%{__global_ldflags} -Wl,--build-id=sha1"
%make_build PREFIX=%{_prefix}

%install
%make_install PREFIX=%{_prefix}


%files
%doc README.md
%license LICENSE
%{_bindir}/ntetris


%changelog
* Wed Feb  8 2017 Michal Vala <mvala@redhat.com> 1.0-1
- initial version created many years ago as a school project
