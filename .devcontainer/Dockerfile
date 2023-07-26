FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.27.1"

COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
    chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh
