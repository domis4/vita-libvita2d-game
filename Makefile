TITLE_ID = VITA2DTST
TARGET   = vita2dsample
SOURCES  = $(wildcard app/src/*.cpp)
ASSETS 	 = $(wildcard app/assets/*.*)
OBJS     = $(SOURCES:**/.*=*.o) $(ASSETS:**/.*=*.o)  
OBJS 	 = $(patsubst %.cpp, %.o, $(SOURCES)) $(patsubst %.cpp, %.o, $(ASSETS))

LIBS = -lvita2d -lSceDisplay_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub -lScePvf_stub \
	-lSceCommonDialog_stub -lfreetype -lpng -ljpeg -lz -lm -lc

PREFIX  = arm-vita-eabi
CXX 	= $(PREFIX)-g++
CXXFLAGS= -Wl,-q -Wall -fno-lto -std=c++11
ASFLAGS = $(CXXFLAGS)
PSVITAIP = "192.168.178.22"

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin $@

eboot.bin: $(TARGET).velf
	vita-make-fself -s $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

%.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) \
		eboot.bin param.sfo

vpksend: $(TARGET).vpk
	curl -T $(TARGET).vpk ftp://$(PSVITAIP):1337/ux0:/
	@echo "Sent."

send: eboot.bin
	curl -T eboot.bin ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE_ID)/
	@echo "Sent."
