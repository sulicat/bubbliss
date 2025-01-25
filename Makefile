EMCC_FLAGS :=   -Os                        					\
				-O2                        					\
				-s USE_GLFW=3              					\
				-s ALLOW_MEMORY_GROWTH=1   					\
				-s TOTAL_MEMORY=16777216   					\
				-s USE_PTHREADS=1          					\
				-s WASM=0                  					\
				-s ASYNCIFY                					\
				-s FORCE_FILESYSTEM=1      					\
				-s ASSERTIONS=1            					\
				-s GL_ENABLE_GET_PROC_ADDRESS 				\
				--profiling                					\
		 		-s USE_GLFW=3								\
				-s LLD_REPORT_UNDEFINED						\
				-DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2	\
				-DPLATFORM_WEB								\
				-Wno-enum-compare 							\



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

run:
	./bin/bubliss

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
		-o bin_web/bubliss.html \
		${EMCC_FLAGS} \

run_web:
	cd bin_web && emrun index.html