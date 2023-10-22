FROM stateoftheartio/qt6:6.6-wasm-aqt

USER root
RUN apt update \
    && apt upgrade -y \
    && apt install -y make \
    && apt clean all \
    && rm -rf /var/lib/apt/lists/*

USER user
