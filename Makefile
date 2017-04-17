TITLE_ID = DOMIS4CPP
TARGET = domis4cpp
SOURCEDIR = app/src
ASSETSDIR = assets
SOURCES = $(shell find $(SOURCEDIR)/ -type f -name '*.cpp')
ASSETS =  $(shell find $(SOURCEDIR)/ -type f -name '*.*')
OBJS = $(patsubst %.cpp, %.o, $(SOURCES))

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

sendAssets: eboot.bin
	find $(ASSETSDIR) -type f -name '*.png' -exec curl --ftp-create-dirs -T {} ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE_ID)/{} \;
	@echo "Sent."