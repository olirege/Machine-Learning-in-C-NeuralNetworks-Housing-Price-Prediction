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
RUN gcc -o nn nn.c utils/use_log.c utils/print_snapshot.c utils/feature_accessors.c files/read_data.c operations/normalize_data.c operations/calculate_std.c operations/calculate_mean.c operations/shuffle_data.c operations/split_data.c nn_operations/initialize.c nn_operations/train.c nn_operations/activation_funcs.c nn_operations/backward.c nn_operations/forward.c nn_operations/update_weights.c nn_operations/test.c

# Command to run the startup script
CMD ["./initialize.sh"]
