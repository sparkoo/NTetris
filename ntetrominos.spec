Name:           ntetrominos
Version:        1.0
Release:        1%{?dist}
Summary:        Simple CLI logical game
Summary(cs):    Jednoduchá terminálová logická hra

License:        MIT
URL:            https://github.com/sparkoo/NTetris
Source0:        https://github.com/sparkoo/NTetris/archive/1.0.tar.gz

BuildRequires:  ncurses-devel
Requires:       ncurses

%description
Build tetromino blocks to fill full lines. Based on Ncurses lib for CLI gaming.

%description -l cs
Postavte tetromino bloky tak, aby zaplnily celé řádky. Napsané pomocí Ncurses knihovny pro hraní v terminálu.

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
%{_bindir}/ntetrominos


%changelog
* Wed Feb  8 2017 Michal Vala <mvala@redhat.com> 1.0-1
- initial version created many years ago as a school project
