FROM ros:lyrical

ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG GIT_NAME=todo
ARG GIT_EMAIL=todo@todo.com

# The base image already ships a "ubuntu" user/group at 1000:1000; adjust it to match the host instead of creating a new one
RUN groupmod --gid $USER_GID $USERNAME \
    && usermod --uid $USER_UID --gid $USER_GID $USERNAME \
    && chown -R $USER_UID:$USER_GID /home/$USERNAME

# Add sudo support
RUN apt-get -y update
RUN apt-get install -y sudo
RUN echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME
RUN chmod 0440 /etc/sudoers.d/$USERNAME
RUN apt-get update && apt-get upgrade -y

RUN apt-get update \
    && apt-get install -y \
        libxcb-cursor0 \
        ros-lyrical-ament-cmake \
        clangd \
        python3-colcon-common-extensions \
        python3-pip \
        vim \
        clang \
        clang-format \
        clang-tidy \
        ros-lyrical-turtlesim \
        ros-lyrical-rqt-common-plugins \
    && rm -rf /var/lib/apt/lists/*

RUN echo "source /opt/ros/lyrical/setup.bash" >> /home/$USERNAME/.bashrc

RUN mkdir -p /ros2_ws && chown -R $USER_UID:$USER_GID /ros2_ws

USER $USERNAME

RUN git config --global user.name "$GIT_NAME" && \
    git config --global user.email "$GIT_EMAIL"

CMD ["bash"]