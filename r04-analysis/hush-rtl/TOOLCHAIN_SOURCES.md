# Local reference-RTL toolchain

The workspace-local installation uses pinned `yowasp-yosys==0.70.0.0.post1259` from PyPI, without modifying the global Python environment. Its actual `-V` output is Yosys0.70, git28ba3cb92. Existing Zig0.14.1 supplies the native C++ compiler. This establishes tool availability only; it is not a synthesis, execution or RTL-conformance result.

Primary documentation checked2026-10-23:

- [YoWASP usage](https://yowasp.org/): the maintainers document the pip package and its Python runtime.
- [Pinned PyPI release](https://pypi.org/project/yowasp-yosys/):0.70.0.0.post1259, release2026-10-13, wheel SHA25638a5ce6af95045b5b1ad795de7a73cfe88cf70c19f7b95f027f4a377a85310c0.
- [Yosys0.70 backend documentation](https://yosyshq.readthedocs.io/projects/yosys/en/v0.70/cmd/index_backends.html):write_cxxrtl emits a C++ design requiring an external clock/input driver. Its documented low/high clock stepping must keep user stimulus away from the sampled edge.

Installed task-local dependencies: yowasp-runtime1.96,wasmtime47.0.1,platformdirs4.13.5,click8.5.0. Tool wrapper `.tools/run_iscas_yosys.py` prepends only the local module directory. No remote machine, service, power, priority or authentication setting was changed. Public research packages must not bundle the installed tools or executable artifacts; record version/commands and use existing compatible tools instead.
