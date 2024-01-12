# Use Alpine Linux as the base image
FROM alpine:latest

# Install dependencies
RUN apk add --no-cache gcc musl-dev curl python3 py3-pip bash

# Set up a Python virtual environment
RUN python3 -m venv /venv
ENV PATH="/venv/bin:$PATH"

# Install Kaggle CLI in the virtual environment
RUN pip install --no-cache-dir kaggle

# Create a directory for your application
WORKDIR /usr/src/app

# Copy the C source code, Kaggle API token, and the startup script into the container
COPY . .
COPY kaggle.json /root/.kaggle/kaggle.json

# Make sure the Kaggle API token is secure
RUN chmod 600 /root/.kaggle/kaggle.json

# Compile the C program
RUN gcc -o nn nn.c utils/use_log.c

# Command to run the startup script
CMD ["./initialize.sh"]
