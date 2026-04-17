import matplotlib.pyplot as plt
import sys

def main():
    print("Please enter your input:")
    print("(n, followed by n lines of x y r, then m, followed by m lines of x y r)")
    
    # Read all input at once
    input_data = sys.stdin.read().split()
    
    if not input_data:
        print("No input provided.")
        return

    try:
        idx = 0
        
        # Parse n blue circles
        n = int(input_data[idx])
        idx += 1
        
        blue_circles = []
        for _ in range(n):
            x = float(input_data[idx])
            y = float(input_data[idx+1])
            r = float(input_data[idx+2])
            blue_circles.append((x, y, r))
            idx += 3
            
        # Parse m red circles
        m = int(input_data[idx])
        idx += 1
        
        red_circles = []
        for _ in range(m):
            x = float(input_data[idx])
            y = float(input_data[idx+1])
            r = float(input_data[idx+2])
            red_circles.append((x, y, r))
            idx += 3
            
    except (IndexError, ValueError):
        print("Error: Incomplete or invalid data. Please check your input format.")
        return

    # Initialize the plot
    fig, ax = plt.subplots()

    # Variables to track the boundaries of the plot
    min_x, max_x = float('inf'), float('-inf')
    min_y, max_y = float('inf'), float('-inf')

    # Helper function to plot circles and update boundaries
    def plot_circles(circles, color):
        nonlocal min_x, max_x, min_y, max_y
        for x, y, r in circles:
            circle = plt.Circle((x, y), r, fill=False, edgecolor=color, linewidth=1.5)
            ax.add_patch(circle)
            
            # Update the boundaries to ensure all circles are visible
            min_x = min(min_x, x - r)
            max_x = max(max_x, x + r)
            min_y = min(min_y, y - r)
            max_y = max(max_y, y + r)

    # Draw both sets of circles
    plot_circles(blue_circles, 'blue')
    plot_circles(red_circles, 'red')

    # Force the axes to have an equal aspect ratio
    ax.set_aspect('equal')

    # Set the calculated limits with a small 10% padding
    if n + m > 0:
        x_pad = (max_x - min_x) * 0.1 if (max_x - min_x) > 0 else 1.0
        y_pad = (max_y - min_y) * 0.1 if (max_y - min_y) > 0 else 1.0
        
        ax.set_xlim(min_x - x_pad, max_x + x_pad)
        ax.set_ylim(min_y - y_pad, max_y + y_pad)

    # Formatting the plot
    plt.title(f"Plot of {n} Blue and {m} Red Circle{'s' if (n+m) != 1 else ''}")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid(True, linestyle='--', alpha=0.6)
    
    # Display the result
    plt.show()

if __name__ == "__main__":
    main()