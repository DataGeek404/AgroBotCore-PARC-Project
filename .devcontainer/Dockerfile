FROM althack/ros2:humble-gazebo

# Install additional dependencies
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    ros-humble-gazebo-ros-pkgs \
    ros-humble-rviz2 \
    ros-humble-image-pipeline \
    libopencv-dev \
    python3-opencv \
    git \
    curl \
    gnupg2 \
    lsb-release \
    bash-completion \
    && rm -rf /var/lib/apt/lists/*

# Create user for VS Code dev container
ARG USERNAME=vscode

# Dynamically find an unused UID and GID (above 1000)
RUN USER_UID=$(sh -c 'i=1010; while getent passwd "$i" >/dev/null; do i=$((i+1)); done; echo $i') && \
    USER_GID=$USER_UID && \
    groupadd --gid $USER_GID $USERNAME && \
    useradd -m $USERNAME --uid $USER_UID --gid $USER_GID && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers.d/nopasswd && \
    chmod 0440 /etc/sudoers.d/nopasswd


# Create workspace folder with correct permissions
RUN mkdir -p /home/vscode/ros_ws/src && chown -R vscode:vscode /home/vscode/ros_ws

# Add this near the end of your Dockerfile
COPY --chown=vscode:vscode ros_ws/ /home/vscode/ros_ws/


USER $USERNAME
WORKDIR /home/$USERNAME
ENV HOME=/home/$USERNAME
ENV DEBIAN_FRONTEND=noninteractive
