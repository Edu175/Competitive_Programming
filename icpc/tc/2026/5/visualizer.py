import sys
import matplotlib.pyplot as plt
import matplotlib.patches as patches

def main():
    # Read all inputs from standard input
    input_data = sys.stdin.read().split()
    if not input_data:
        print("Please provide the input data.")
        return

    ptr = 0
    
    # 1. Read Bob's polygon vertex count (n) and lane width (w)
    n = int(input_data[ptr])
    w = int(input_data[ptr+1])
    ptr += 2

    # 2. Read Bob's polygon vertices
    bob_points = []
    for _ in range(n):
        x = int(input_data[ptr])
        y = int(input_data[ptr+1])
        bob_points.append((x, y))
        ptr += 2

    # 3. Read number of jellyfish (m)
    m = int(input_data[ptr])
    ptr += 1

    # 4. Read jellyfish data (x, y, radius)
    jellyfishes = []
    for _ in range(m):
        x = int(input_data[ptr])
        y = int(input_data[ptr+1])
        r = int(input_data[ptr+2])
        jellyfishes.append((x, y, r))
        ptr += 3

    # --- Plotting ---
    fig, ax = plt.subplots(figsize=(10, 8))

    # Plot the pool lane (x=0 to x=w)
    ax.axvline(x=0, color='black', linestyle='--', linewidth=2, label='Lane Boundary (x=0)')
    ax.axvline(x=w, color='black', linestyle='--', linewidth=2, label=f'Lane Boundary (x={w})')
    ax.axvspan(0, w, color='aliceblue', alpha=0.4, label='Pool Lane')

    # Plot Bob's reference shape
    bob_poly = patches.Polygon(bob_points, closed=True, linewidth=2, 
                               edgecolor='blue', facecolor='cyan', alpha=0.6, 
                               label="Bob's Shape (Reference)")
    ax.add_patch(bob_poly)
    
    # Plot Bob's starting vertex (which the editorial mentions as his reference point)
    ax.plot(bob_points[0][0], bob_points[0][1], 'bo', markersize=6, label="Bob's First Vertex")

    # Plot the Jellyfish
    for i, (x, y, r) in enumerate(jellyfishes):
        # We only add the label to the first one to avoid cluttering the legend
        label = 'Jellyfish Activity Area' if i == 0 else None
        jelly = patches.Circle((x, y), r, linewidth=1.5, edgecolor='red', 
                               facecolor='salmon', alpha=0.3, label=label)
        ax.add_patch(jelly)
        ax.plot(x, y, 'r.', markersize=5) # Mark the center

    # Axis settings
    ax.set_aspect('equal', adjustable='datalim')
    ax.autoscale_view()
    
    # Add grid and labels
    ax.set_title("Jellyfish Problem Visualizer", fontsize=14, fontweight='bold')
    ax.set_xlabel("X coordinate")
    ax.set_ylabel("Y coordinate")
    ax.grid(True, linestyle=':', alpha=0.7)
    
    # Place legend outside the plot
    ax.legend(loc='upper left', bbox_to_anchor=(1.02, 1), borderaxespad=0.)
    plt.tight_layout()
    
    # Show the plot
    plt.show()

if __name__ == '__main__':
    main()