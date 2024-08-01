class GarbageCollection {
  public static void main(String[] args) {
    // Create some "toys" (objects)
    String toy1 = "teddy bear";
    String toy2 = "doll";

    // We're done playing with these toys, so we "put them away"
    toy1 = null;
    toy2 = null;

    // Ask the garbage collector to clean up (but it might not do it right away)
    System.gc();
  }
}
