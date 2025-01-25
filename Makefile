all:
	@mkdir -p bin
	g++ \
		src/main.cpp \
		src/game_state.cpp \
		src/scene.cpp \
		src/gameplay_system.cpp \
		src/rendering_system.cpp \
		-o bin/bubliss -L ./third_party/raylib-5.5_linux_amd64/lib/ -lraylib \
		-I include \
		-I ./third_party/raylib-5.5_linux_amd64/include \
		-I ./third_party/ \
		-Wno-enum-compare

web:
	@mkdir -p bin_web
	emcc \
		src/main.cpp \
		src/game_state.cpp \
		src/scene.cpp \
		src/gameplay_system.cpp \
		src/rendering_system.cpp \
		-L ./third_party/raylib-5.5_webassembly/lib/ \
		-lraylib \
		-I include \
		-I ./third_party/raylib-5.5_webassembly/include \
		-I ./third_party/ \
		-s USE_GLFW=3 \
		-s LLD_REPORT_UNDEFINED \
		-DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 \
		-DPLATFORM_WEB \
		-o bin_web/bubliss.html \
		-Wno-enum-compare

run_web:
	cd bin_web && emrun bubliss.html