FROM flaviostutz/opencv-x86

ADD . /opt/monot-vision

RUN cd /opt/monot-vision/src && ../build/compile.sh

CMD [ "/opt/monot-vision/tmp/monot-vision" ]
