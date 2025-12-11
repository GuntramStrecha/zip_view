window.BENCHMARK_DATA = {
  "lastUpdate": 1765473073465,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark": [
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "0da400dc7dae9a77d4758064ae1bb669d096408c",
          "message": "fixup! Add benchmarks to github actions",
          "timestamp": "2025-12-11T17:55:34+01:00",
          "tree_id": "b7283276692604ec67c793bcbbef41df30ad78aa",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/0da400dc7dae9a77d4758064ae1bb669d096408c"
        },
        "date": 1765472261786,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 138.197,
            "range": "± 23.5564",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 138.731,
            "range": "± 22.4183",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 578.167,
            "range": "± 60.8681",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 566.845,
            "range": "± 73.5245",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 144.633,
            "range": "± 19.8292",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 151.628,
            "range": "± 21.8796",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 157.512,
            "range": "± 20.5731",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 141.232,
            "range": "± 22.9613",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "bc7b11b7c8f86970b5043b73a0f358b85fc4f256",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:02:25+01:00",
          "tree_id": "eee1611d6cee63bcabc34085c248e2d21006f370",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/bc7b11b7c8f86970b5043b73a0f358b85fc4f256"
        },
        "date": 1765472679126,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 92.4671,
            "range": "± 22.2665",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 96.9448,
            "range": "± 22.8182",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 293.24,
            "range": "± 47.6786",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 291.55,
            "range": "± 42.1359",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 88.5148,
            "range": "± 25.4407",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 87.5244,
            "range": "± 24.8601",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 161.152,
            "range": "± 11.3001",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 92.7358,
            "range": "± 23.4595",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "1bf0ff46335b7edf5831c5a4dacc1d0219cf9891",
          "message": "Simplify min_size function to avoid min_value templates",
          "timestamp": "2025-12-11T18:08:55+01:00",
          "tree_id": "deaf1246494438052e9278b4f6aac87d4a39f87e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/1bf0ff46335b7edf5831c5a4dacc1d0219cf9891"
        },
        "date": 1765473073042,
        "tool": "catch2",
        "benches": [
          {
            "name": "std::ranges::views::zip Accumulate",
            "value": 85.2467,
            "range": "± 19.3727",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Accumulate",
            "value": 92.6999,
            "range": "± 19.5604",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Transform",
            "value": 249.082,
            "range": "± 67.8187",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Transform",
            "value": 245.502,
            "range": "± 63.6921",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Construct",
            "value": 75.7541,
            "range": "± 13.6048",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Construct",
            "value": 79.0529,
            "range": "± 18.4913",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std::ranges::views::zip Iterate",
            "value": 161.596,
            "range": "± 20.1678",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst::ranges::views::zip Iterate",
            "value": 88.5161,
            "range": "± 20.2074",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}
